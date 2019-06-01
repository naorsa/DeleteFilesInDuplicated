\ LP format - for model browsing. Use MPS format to capture full model detail.
Maximize
  500 C4 + 300 C5 + 200 C6 + 100 C7 + 300 C8
Subject To
 R0: C0 + C1 + C2 + C3 <= 2
 R1: - C0 + C4 <= 0
 R2: - C0 + C5 <= 0
 R3: - C1 + C4 <= 0
 R4: - C1 + C6 <= 0
 R5: - C2 + C5 <= 0
 R6: - C2 + C7 <= 0
 R7: - C3 + C5 <= 0
 R8: - C3 + C7 <= 0
Bounds
Binaries
 C0 C1 C2 C3 C4 C5 C6 C7 C8
End
