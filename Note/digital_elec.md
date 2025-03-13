TsingHua University--Digital Electronic Class From Wang Hong 

Grey Code <br>
格雷码(グレイコード),a kind of arranging method,one's binary code is different with last one's (only one number)
In k-map<br>
|       | **00** | **01** | **11** | **10** |
|-------|--------|--------|--------|--------|
| **00**| 0000(d1)  | 0001   | 0011   | 0010   |
| **01**| 0100(d2)  | 0101   | 0111   | 0110   |
| **11**| 1100   | 1101   | 1111   | 1110   |
| **10**| 1000   | 1001   | 1011   | 1010   |


Veriable-Length Encoding<br>
哈夫曼编码(Huffman Coding,ハフマン符号),use'0' and '1'to describe high and low probable choices.And finally will get a tree.


布尔恒等式<br>
| **类别**         | **恒等式**                                                                 |
|------------------|---------------------------------------------------------------------------|
| **恒等律**       | \( A + 0 = A \)                                                           |
|                  | \( A • 1 = A \)                                                       |
| **零元律**       | \( A + 1 = 1 \)                                                           |
|                  | \( A \cdot 0 = 0 \)                                                       |
| **幂等律**       | \( A + A = A \)                                                           |
|                  | \( A \cdot A = A \)                                                       |
| **互补律**       | \( A + \overline{A} = 1 \)                                                |
|                  | \( A \cdot \overline{A} = 0 \)                                            |
| **双重否定律**   | \( \overline{\overline{A}} = A \)                                         |
| **交换律**       | \( A + B = B + A \)                                                       |
|                  | \( A \cdot B = B \cdot A \)                                               |
| **结合律**       | \( A + (B + C) = (A + B) + C \)                                           |
|                  | \( A \cdot (B \cdot C) = (A \cdot B) \cdot C \)                           |
| **分配律**       | \( A \cdot (B + C) = A \cdot B + A \cdot C \)                             |