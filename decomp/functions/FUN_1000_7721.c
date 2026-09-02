/* 1000:7721 */

undefined4
FUN_1000_7721(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  byte bVar1;
  uint in_AX;
  int in_CX;
  int iVar2;
  int iVar3;
  int in_DX;
  uint uVar4;
  uint extraout_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_DS;
  undefined4 uVar5;
  uint uVar6;
  
  uVar4 = (in_DX * 2 + (uint)CARRY2(in_AX,in_AX)) * 2 + (uint)CARRY2(in_AX * 2,in_AX * 2);
  *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) | (byte)uVar4;
  if ((uVar4 < *(uint *)(in_BX + 10)) ||
     ((uVar6 = uVar4, uVar4 <= *(uint *)(in_BX + 10) && (in_AX * 4 < *(uint *)(in_BX + 8))))) {
    if (in_CX == 1) {
      FUN_1000_2f02();
      uVar5 = func_0x0001dc6f();
      return uVar5;
    }
    FUN_1000_2f08(uVar4);
    uVar6 = 0x7755;
    func_0x0001dc75();
    uVar4 = extraout_DX;
  }
  iVar2 = 3;
  do {
    iVar3 = 3;
    do {
      FUN_1000_6ab8(iVar2,uVar4,uVar6);
      bVar1 = *(byte *)(in_BX + -0x2d82);
      if ((bVar1 < 0x30) || (0x5f < bVar1)) {
        if ((bVar1 < 0x20) || (0x2f < bVar1)) {
          if ((bVar1 == 0) || (4 < bVar1)) {
            if ((0x5f < bVar1) && (bVar1 < 0x70)) {
              FUN_1000_78c3();
            }
          }
          else {
            FUN_1000_7885();
          }
        }
        else {
          func_0x0001783a();
        }
      }
      else {
        FUN_1000_77c1();
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar4 = (uint)(byte)((char)uVar4 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(param_2,param_4);
}


