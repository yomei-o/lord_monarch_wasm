/* 1000:0efe */

int FUN_1000_0efe(void)

{
  undefined1 uVar1;
  undefined2 in_AX;
  
  uVar1 = in(0x3a);
  return CONCAT11((char)((uint)in_AX >> 8),uVar1) + -0x175;
}


