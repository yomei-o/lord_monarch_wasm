/* 1000:0f08 */

int FUN_1000_0f08(void)

{
  int in_AX;
  int iVar1;
  int unaff_SI;
  undefined2 unaff_DS;
  byte in_CF;
  
  iVar1 = (in_AX + 0x2b76) - (uint)in_CF;
  if (*(byte *)(unaff_SI + 0x1e) < 0xf8) {
    iVar1 = CONCAT11((char)((uint)iVar1 >> 8) + '@',(char)iVar1);
  }
  return iVar1;
}


