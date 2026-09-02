/* 1000:3d2c */

undefined4 __cdecl16near FUN_1000_3d2c(void)

{
  byte bVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  
  bVar1 = *(byte *)(unaff_SI + 1);
  iVar2 = 4;
  do {
    FUN_1000_9ad3();
    FUN_1000_ad80();
    if (!(bool)in_CF) {
      FUN_1000_9b34();
      FUN_1000_3d5e();
      if (!(bool)in_CF) {
        *(byte *)(unaff_SI + 1) = bVar1 & 7;
        break;
      }
    }
    in_CF = 0xfd < bVar1;
    bVar1 = bVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_DX,in_AX);
}


