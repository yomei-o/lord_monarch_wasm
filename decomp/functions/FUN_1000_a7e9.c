/* 1000:a7e9 */

undefined4 __cdecl16near FUN_1000_a7e9(void)

{
  undefined2 in_AX;
  int iVar1;
  int iVar2;
  byte bVar3;
  undefined2 in_DX;
  int in_BX;
  undefined2 unaff_DS;
  uint uVar4;
  
  bVar3 = (char)in_DX - 1;
  iVar1 = 3;
  do {
    uVar4 = (uint)bVar3;
    iVar2 = 3;
    do {
      FUN_1000_9b34(iVar1,uVar4);
      bVar3 = ((undefined *)&DAT_0000_d27e)[in_BX];
      if ((bVar3 < 0x30) || (0x5f < bVar3)) {
        if ((bVar3 < 0x20) || (0x2f < bVar3)) {
          if ((bVar3 == 0) || (4 < bVar3)) {
            if ((0x5f < bVar3) && (bVar3 < 0x70)) {
              FUN_1000_a93f();
            }
          }
          else {
            FUN_1000_a904();
          }
        }
        else {
          FUN_1000_a8b6();
        }
      }
      else {
        FUN_1000_a83d();
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    bVar3 = (char)uVar4 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return CONCAT22(in_DX,in_AX);
}


