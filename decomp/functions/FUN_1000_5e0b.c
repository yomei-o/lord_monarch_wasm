/* 1000:5e0b */

undefined2 FUN_1000_5e0b(void)

{
  byte bVar1;
  byte in_DL;
  byte *unaff_SI;
  undefined2 unaff_DS;
  
  bVar1 = *unaff_SI;
  *(char *)0xe432 = *(char *)0xe432 + in_DL + CARRY1(bVar1 & 0xe,in_DL);
  bVar1 = ~((byte)((bVar1 & 0xe) + in_DL) / in_DL);
  return CONCAT11(bVar1,bVar1);
}


