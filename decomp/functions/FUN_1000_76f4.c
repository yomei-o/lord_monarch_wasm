/* 1000:76f4 */

/* WARNING: Instruction at (ram,0x00017772) overlaps instruction at (ram,0x00017771)
    */
/* WARNING: Removing unreachable block (ram,0x00017763) */

undefined4 FUN_1000_76f4(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  byte bVar1;
  uint in_AX;
  uint uVar2;
  int in_CX;
  int iVar3;
  undefined2 in_DX;
  uint uVar4;
  uint extraout_DX;
  int in_BX;
  int unaff_BP;
  int unaff_SI;
  int iVar5;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool in_CF;
  bool bVar6;
  
  if (!in_CF) {
    return CONCAT22(in_DX,in_AX);
  }
  *(uint *)(unaff_BP + unaff_SI) = *(uint *)(unaff_BP + unaff_SI) ^ in_AX;
  iVar5 = 0x205a;
  uVar4 = 0;
  uVar2 = 0;
  do {
    if (in_BX != iVar5) {
      bVar6 = CARRY2(uVar2,*(uint *)(iVar5 + 8));
      uVar2 = uVar2 + *(uint *)(iVar5 + 8);
      uVar4 = uVar4 + *(int *)(iVar5 + 10) + (uint)bVar6;
    }
    iVar5 = iVar5 + 0x16;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  if (*(uint *)(in_BX + 10) < uVar4) {
LAB_1000_773a_1:
    if ((*(uint *)0x3bc6 & 1) == 0) goto LAB_1000_7771_1;
    *(uint *)0x3bc6 = *(uint *)0x3bc6 & 0xfffe;
    func_0x0001dc56(0x205a);
  }
  else {
    if (*(uint *)(in_BX + 10) <= uVar4) {
      if (*(uint *)(in_BX + 8) < uVar2) goto LAB_1000_773a_1;
      if (*(uint *)(in_BX + 8) <= uVar2) {
        return CONCAT22(uVar4,uVar2);
      }
    }
    uVar4 = (uVar4 * 2 + (uint)CARRY2(uVar2,uVar2)) * 2 + (uint)CARRY2(uVar2 * 2,uVar2 * 2);
    *(byte *)(in_BX + iVar5) = *(byte *)(in_BX + iVar5) | (byte)uVar4;
    if ((*(uint *)(in_BX + 10) <= uVar4) &&
       ((*(uint *)(in_BX + 10) < uVar4 || (*(uint *)(in_BX + 8) <= uVar2 * 4))))
    goto LAB_1000_7771_1;
  }
  FUN_1000_2f08();
  func_0x0001dc75();
  uVar4 = extraout_DX;
LAB_1000_7771_1:
  iVar5 = 3;
  do {
    iVar3 = 3;
    do {
      FUN_1000_6ab8(iVar5,uVar4);
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
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return CONCAT22(param_1,param_3);
}


