class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        matrix=mat
        if not matrix or not matrix[0]:
            return []

        diagonal_dict = {}
        m, n = len(matrix), len(matrix[0])

        # Populate the diagonal dictionary
        for i in range(m):
            for j in range(n):
                diagonal_sum = i + j
                if diagonal_sum not in diagonal_dict:
                    diagonal_dict[diagonal_sum] = []
                diagonal_dict[diagonal_sum].append(matrix[i][j])

        result = []

        # Concatenate the diagonals in zigzag order
        for diagonal_sum in range(m + n - 1):
            if diagonal_sum % 2 == 0:
                result.extend(reversed(diagonal_dict.get(diagonal_sum, [])))
            else:
                result.extend(diagonal_dict.get(diagonal_sum, []))

        return result

    