-- This is a sample custom writer for pandoc.  It produces output
-- that is very similar to that of pandoc's HTML writer.
-- There is one new feature: code blocks marked with class 'dot'
-- are piped through graphviz and images are included in the HTML
-- output using 'data:' URLs. The image format can be controlled
-- via the `image_format` metadata field.
--
-- Invoke with: pandoc -t sample.lua
--
-- Note:  you need not have lua installed on your system to use this
-- custom writer.  However, if you do have lua installed, you can
-- use it to test changes to the script.  'lua sample.lua' will
-- produce informative error messages if your code contains
-- syntax errors.

local pipe = pandoc.pipe
local stringify = (require "pandoc.utils").stringify

-- The global variable PANDOC_DOCUMENT contains the full AST of
-- the document which is going to be written. It can be used to
-- configure the writer.
local meta = PANDOC_DOCUMENT.meta

-- Chose the image format based on the value of the
-- `image_format` meta value.
local image_format = meta.image_format
  and stringify(meta.image_format)
  or "png"
local image_mime_type = ({
    jpeg = "image/jpeg",
    jpg = "image/jpeg",
    gif = "image/gif",
    png = "image/png",
    svg = "image/svg+xml",
  })[image_format]
  or error("unsupported image format `" .. img_format .. "`")

-- t = table
-- f = filename [optional]
function printTable(t, f)

   local function printTableHelper(obj, cnt)

      local cnt = cnt or 0

      if type(obj) == "table" then

         io.write("\n", string.rep("\t", cnt), "{\n")
         cnt = cnt + 1

         for k,v in pairs(obj) do

            if type(k) == "string" then
               io.write(string.rep("\t",cnt), '["'..k..'"]', ' = ')
            end

            if type(k) == "number" then
               io.write(string.rep("\t",cnt), "["..k.."]", " = ")
            end

            printTableHelper(v, cnt)
            io.write(",\n")
         end

         cnt = cnt-1
         io.write(string.rep("\t", cnt), "}")

      elseif type(obj) == "string" then
         io.write(string.format("%q", obj))

      else
         io.write(tostring(obj))
      end 
   end

   if f == nil then
      printTableHelper(t)
   else
      io.output(f)
      io.write("return")
      printTableHelper(t)
      io.output(io.stdout)
   end
end

function splitString_t(s, d)

   if (type(s) ~= "string") or (type(d) ~= "string") then
      return nil
   end

   local Result_t = {}

   if s == "" then
      return Result_t
   end

   if d == "" then
      table.insert(Result_t, s)
      return Result_t
   end
 
   local Start = 1
   local SplitStart, SplitEnd = string.find(s, d, Start)
 
   while SplitStart do
      table.insert(Result_t, string.sub(s, Start, SplitStart-1))
      Start = SplitEnd + 1
      SplitStart, SplitEnd = string.find(s, d, Start)
   end
   table.insert(Result_t, string.sub(s, Start)) -- insert remaining string into table
 
   return Result_t
end

-- Table to store footnotes, so they can be included at the end.
local notes = {}

-- This function is called once for the whole document. Parameters:
-- body is a string, metadata is a table, variables is a table.
-- This gives you a fragment.  You could use the metadata table to
-- fill variables in a custom lua template.  Or, pass `--template=...`
-- to pandoc, and pandoc will add do the template processing as
-- usual.
function Doc(body, metadata, variables)
  local buffer = {}
  local function add(s)
    table.insert(buffer, s)
  end
  add("*pinocchio.txt*\t                               GCC                                   \t" .. os.date("%Y-%m-%d"))
  add(body)
  if #notes > 0 then
    add('<ol class="footnotes">')
    for _,note in pairs(notes) do
      add(note)
    end
    add('</ol>')
  end
  add("\nvim:tw=100:ts=3:ft=help")
  return table.concat(buffer,'\n') .. '\n'
end

function Link(s, src, tit, attr)
   if string.sub(src,1,1) == '#' then
      return s .. " |pinocchio-" .. string.sub(src,2) .. "|"
   else
      return src
   end
end

function BulletList(items)
   local buffer = {}
   for _,item in ipairs(items) do
      local SplitLines = splitString_t(item, "\n+")
      for i,l in ipairs(SplitLines) do
         SplitLines[i] = "  " .. l
         if string.sub(l, -1) == "|" then -- assuming it's the table of content
            SplitLines[i] = string.gsub(SplitLines[i], " *%.* |", " |", 1)
            local CurLen = string.len(SplitLines[i])
            SplitLines[i] = string.gsub(SplitLines[i], " |", " " .. string.rep(".",101-CurLen).." |", 1)
         end
      end
      table.insert(buffer, table.concat(SplitLines, "\n"))
   end
   return table.concat(buffer, "\n")
end

-- lev is an integer, the header level.
local Levels = {"=", "-"}
function Header(lev, s, attr)
   local H
   if(lev <= 2) then
      H = string.rep(Levels[lev] or "", 100) .. "\n" .. string.rep(" ", 90 - string.len(attr.id))
      .. "*pinocchio-" .. attr.id .. "*" .. "\n" .. s .. "~" --.. "\n"
   elseif(lev==3) then
      H = string.rep(" ", 90 - string.len(attr.id)) .. "*pinocchio-" .. attr.id .. "*" .. "\n" .. s .. "~" --.. "\n"
   else
      H = s .. "~" --.. "\n"
   end
   return H
end

function Space()
  return " "
end

function Str(s)
  return s
end

function Plain(s)
  return s
end

-- Blocksep is used to separate block elements.
function Blocksep()
  return "\n\n"
end

function Para(s)
  return s
end

function Emph(s)
  return "<" .. s .. ">"
end

function Strong(s)
  return "{" .. s .. "}"
end

function SoftBreak()
  return "\n"
end

function LineBreak()
  return "\n"
end

function Code(s, attr)
  return "`" .. s .. "`"
end

function CodeBlock(s, attr)
   local SplitLines = splitString_t(s, "\n")
   for i,l in ipairs(SplitLines) do
      SplitLines[i] = "  " .. l
   end
   return ">\n" .. table.concat(SplitLines, "\n") .. "\n<"
end

function HorizontalRule()
  return string.rep("─", 100)
end


--[===[ <<<
-- Character escaping
local function escape(s, in_attribute)
  return s:gsub("[<>&\"']",
    function(x)
      if x == '<' then
        return '&lt;'
      elseif x == '>' then
        return '&gt;'
      elseif x == '&' then
        return '&amp;'
      elseif x == '"' then
        return '&quot;'
      elseif x == "'" then
        return '&#39;'
      else
        return x
      end
    end)
end

-- Helper function to convert an attributes table into
-- a string that can be put into HTML tags.
local function attributes(attr)
  local attr_table = {}
  for x,y in pairs(attr) do
    if y and y ~= "" then
      table.insert(attr_table, ' ' .. x .. '="' .. escape(y,true) .. '"')
    end
  end
  return table.concat(attr_table)
end



-- The functions that follow render corresponding pandoc elements.
-- s is always a string, attr is always a table of attributes, and
-- items is always an array of strings (the items in a list).
-- Comments indicate the types of other variables.




function Subscript(s)
  return "_" .. s
end

function Superscript(s)
  return "^" .. s
end

function SmallCaps(s)
  return s
end

function Strikeout(s)
  return s
end

function Image(s, src, tit, attr)
  return "<img src='" .. escape(src,true) .. "' title='" ..
         escape(tit,true) .. "'/>"
end


function InlineMath(s)
  return s
end

function DisplayMath(s)
  return s
end

function SingleQuoted(s)
  return "'" .. s .. "'"
end

function DoubleQuoted(s)
  return '"' .. s .. '"'
end

function Note(s)
  local num = #notes + 1
  -- insert the back reference right before the final closing tag.
  s = string.gsub(s,
          '(.*)</', '%1 <a href="#fnref' .. num ..  '">&#8617;</a></')
  -- add a list item with the note to the note table.
  table.insert(notes, '<li id="fn' .. num .. '">' .. s .. '</li>')
  -- return the footnote reference, linked to the note.
  return '<a id="fnref' .. num .. '" href="#fn' .. num ..
            '"><sup>' .. num .. '</sup></a>'
end

function Span(s, attr)
  return s
end

function RawInline(format, str)
    return str
end

function Cite(s, cs)
  local ids = {}
  for _,cit in ipairs(cs) do
    table.insert(ids, cit.citationId)
  end
  return "<span class=\"cite\" data-citation-ids=\"" .. table.concat(ids, ",") ..
    "\">" .. s .. "</span>"
end

function BlockQuote(s)
  return "\n>\n" .. s .. "\n<\n"
end

function LineBlock(ls)
  return '<div style="white-space: pre-line;">' .. table.concat(ls, '\n') .. '</div>'
end

function OrderedList(items)
  local buffer = {}
  for _, item in pairs(items) do
    table.insert(buffer, "<li>" .. item .. "</li>")
  end
  return "<ol>\n" .. table.concat(buffer, "\n") .. "\n</ol>"
end

function DefinitionList(items)
  local buffer = {}
  for _,item in pairs(items) do
    local k, v = next(item)
    table.insert(buffer, "<dt>" .. k .. "</dt>\n<dd>" ..
                   table.concat(v, "</dd>\n<dd>") .. "</dd>")
  end
  return "<dl>\n" .. table.concat(buffer, "\n") .. "\n</dl>"
end

-- Convert pandoc alignment to something HTML can use.
-- align is AlignLeft, AlignRight, AlignCenter, or AlignDefault.
function html_align(align)
  if align == 'AlignLeft' then
    return 'left'
  elseif align == 'AlignRight' then
    return 'right'
  elseif align == 'AlignCenter' then
    return 'center'
  else
    return 'left'
  end
end

function CaptionedImage(src, tit, caption, attr)
   return '<div class="figure">\n<img src="' .. escape(src,true) ..
      '" title="' .. escape(tit,true) .. '"/>\n' ..
      '<p class="caption">' .. caption .. '</p>\n</div>'
end

-- Caption is a string, aligns is an array of strings,
-- widths is an array of floats, headers is an array of
-- strings, rows is an array of arrays of strings.
function Table(caption, aligns, widths, headers, rows)
  local buffer = {}
  local function add(s)
    table.insert(buffer, s)
  end
  add("<table>")
  if caption ~= "" then
    add("<caption>" .. caption .. "</caption>")
  end
  if widths and widths[1] ~= 0 then
    for _, w in pairs(widths) do
      add('<col width="' .. string.format("%.0f%%", w * 100) .. '" />')
    end
  end
  local header_row = {}
  local empty_header = true
  for i, h in pairs(headers) do
    local align = html_align(aligns[i])
    table.insert(header_row,'<th align="' .. align .. '">' .. h .. '</th>')
    empty_header = empty_header and h == ""
  end
  if empty_header then
    head = ""
  else
    add('<tr class="header">')
    for _,h in pairs(header_row) do
      add(h)
    end
    add('</tr>')
  end
  local class = "even"
  for _, row in pairs(rows) do
    class = (class == "even" and "odd") or "even"
    add('<tr class="' .. class .. '">')
    for i,c in pairs(row) do
      add('<td align="' .. html_align(aligns[i]) .. '">' .. c .. '</td>')
    end
    add('</tr>')
  end
  add('</table>')
  return table.concat(buffer,'\n')
end

function RawBlock(format, str)
  if format == "html" then
    return str
  else
    return ''
  end
end

function Div(s, attr)
  return "<div" .. attributes(attr) .. ">\n" .. s .. "</div>"
end
>>>
--]===]

-- The following code will produce runtime warnings when you haven't defined
-- all of the functions you need for the custom writer, so it's useful
-- to include when you're working on a writer.
local meta = {}
meta.__index =
  function(_, key)
    io.stderr:write(string.format("WARNING: Undefined function '%s'\n",key))
    return function() return "" end
  end
setmetatable(_G, meta)

