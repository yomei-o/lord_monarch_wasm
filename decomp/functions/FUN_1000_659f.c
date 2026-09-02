/* 1000:659f */

undefined2 FUN_1000_659f(void)

{
  undefined2 in_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  
  return CONCAT11((byte)((uint)in_DX >> 8) | *(byte *)(in_BX + unaff_SI),(char)in_DX + '/');
}


