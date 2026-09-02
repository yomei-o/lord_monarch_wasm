/* 1000:5ab9 */

undefined4 FUN_1000_5ab9(void)

{
  byte in_AL;
  undefined2 in_DX;
  
  return CONCAT22(in_DX,(uint)(byte)((in_AL >> 4) * '\n' + (in_AL & 0xf)));
}


