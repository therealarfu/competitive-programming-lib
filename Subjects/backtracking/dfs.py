class Solution:
    def letterCombinations(self, digits: str) -> list[str]:
        result = []
        mapa = ['', '', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
        def bt_dfs(path):
            if (len(path) == len(digits)):
                result.append(''.join(path))
                return

            mapaid = int(digits[len(path)])
            sizenomapa = len(mapa[mapaid])
            for i in range(sizenomapa):
                path.append(mapa[mapaid][i])
                bt_dfs(path)
                path.pop()
        
        bt_dfs([])
        return result    
            

            