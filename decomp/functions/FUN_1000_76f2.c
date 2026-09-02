/* 1000:76f2 */

/* WARNING: Instruction at (ram,0x00017772) overlaps instruction at (ram,0x00017771)
    */
/* WARNING: Removing unreachable block (ram,0x00017763) */

undefined4 FUN_1000_76f2(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  byte bVar1;
  undefined2 in_AX;
  uint uVar2;
  int in_CX;
  int iVar3;
  uint uVar4;
  uint extraout_DX;
  int in_BX;
  int iVar5;
  int unaff_BP;
  int unaff_SI;
  int iVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar7;
  
  uVar4 = CONCAT11((char)((uint)in_AX >> 8),(char)in_AX + 'r');
  iVar5 = in_BX + uVar4;
  *(uint *)(unaff_BP + unaff_SI) = *(uint *)(unaff_BP + unaff_SI) ^ uVar4;
  iVar6 = 0x205a;
  uVar4 = 0;
  uVar2 = 0;
  do {
    if (iVar5 != iVar6) {
      bVar7 = CARRY2(uVar2,*(uint *)(iVar6 + 8));
      uVar2 = uVar2 + *(uint *)(iVar6 + 8);
      uVar4 = uVar4 + *(int *)(iVar6 + 10) + (uint)bVar7;
    }
    iVar6 = iVar6 + 0x16;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  if (*(uint *)(iVar5 + 10) < uVar4) {
LAB_1000_773a_1:
    if ((*(uint *)0x3bc6 & 1) == 0) goto LAB_1000_7771_1;
    *(uint *)0x3bc6 = *(uint *)0x3bc6 & 0xfffe;
    func_0x0001dc56(0x205a);
  }
  else {
    if (*(uint *)(iVar5 + 10) <= uVar4) {
      if (*(uint *)(iVar5 + 8) < uVar2) goto LAB_1000_773a_1;
      if (*(uint *)(iVar5 + 8) <= uVar2) {
        return CONCAT22(uVar4,uVar2);
      }
    }
    uVar4 = (uVar4 * 2 + (uint)CARRY2(uVar2,uVar2)) * 2 + (uint)CARRY2(uVar2 * 2,uVar2 * 2);
    *(byte *)(iVar5 + iVar6) = *(byte *)(iVar5 + iVar6) | (byte)uVar4;
    if ((*(uint *)(iVar5 + 10) <= uVar4) &&
       ((*(uint *)(iVar5 + 10) < uVar4 || (*(uint *)(iVar5 + 8) <= uVar2 * 4))))
    goto LAB_1000_7771_1;
  }
  FUN_1000_2f08();
  func_0x0001dc75();
  uVar4 = extraout_DX;
LAB_1000_7771_1:
  iVar6 = 3;
  do {
    iVar3 = 3;
    do {
      FUN_1000_6ab8(iVar6,uVar4);
      bVar1 = *(byte *)(iVar5 + -0x2d82);
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
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return CONCAT22(param_1,param_3);
}


