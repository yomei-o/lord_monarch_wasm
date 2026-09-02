/* 1000:4947 */

undefined4 __cdecl16near FUN_1000_4947(void)

{
  byte bVar1;
  undefined2 in_AX;
  int iVar2;
  undefined2 in_DX;
  undefined2 extraout_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool bVar3;
  
  bVar1 = *(byte *)(unaff_SI + 1);
  iVar2 = 4;
  while( true ) {
    FUN_1000_9ad3();
    FUN_1000_ad80();
    if ((!(bool)in_CF) && (FUN_1000_9b34(), (byte)((undefined *)&DAT_0000_d27e)[in_BX] < 0x30))
    break;
    in_CF = 0xfd < bVar1;
    bVar1 = bVar1 + 2;
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
LAB_1000_49a2:
      return CONCAT22(in_DX,in_AX);
    }
  }
  bVar3 = false;
  *(byte *)(unaff_SI + 1) = bVar1 & 7;
  FUN_1000_3d5e();
  if ((bVar3) &&
     (((FUN_1000_3e21(), bVar3 &&
       (bVar3 = false, *(int *)((undefined *)&DAT_0000_e47e + in_BX) == 0)) &&
      (FUN_1000_4163(), bVar3)))) {
    *(int *)((undefined *)&DAT_0000_e47e + in_BX) = unaff_SI;
    LOCK();
    iVar2 = *(int *)(unaff_SI + 4);
    *(int *)(unaff_SI + 4) = in_BX;
    UNLOCK();
    *(undefined2 *)((undefined *)&DAT_0000_e47e + iVar2) = 0;
    *(undefined2 *)(unaff_SI + 2) = extraout_DX;
  }
  goto LAB_1000_49a2;
}


