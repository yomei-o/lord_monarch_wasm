/* 1000:75c3 */

void FUN_1000_75c3(void)

{
  uint in_AX;
  undefined2 in_DX;
  uint *unaff_DI;
  undefined2 unaff_ES;
  
  *unaff_DI = in_AX & 0xff55;
  out(in_DX,in_AX & 0xff55);
  return;
}


