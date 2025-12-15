# @param {Integer} n
# @return {String[]}
def generate_parenthesis(n)
  n == 0 ? [''] : expand(n)
end

def expand(n, s = '(', c = '', l=1,r=0)
  return [s + ')'] if l == n && r == n
  arr = []
  arr.concat(expand(n, s + c, '(', l+1, r)) if l < n
  arr.concat(expand(n, s + c, ')', l, r+1)) if r < l
  arr
end