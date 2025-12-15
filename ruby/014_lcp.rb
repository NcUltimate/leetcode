# @param {String[]} strs
# @return {String}
def longest_common_prefix(strs)
  return '' unless strs.length > 0
  return strs[0] if strs.length == 1
  
  c = 0
  while true
    idx = 0
    ch = strs[0][c]
    all_nil = true
    until idx == strs.length
      return strs[0][0...c] if strs[idx][c] != ch
      all_nil &&= ( strs[idx][c] == nil)
      idx += 1
    end
    c += 1
    return strs[0] if all_nil
  end
  ''
end