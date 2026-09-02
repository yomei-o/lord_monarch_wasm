/* 1000:7700 */

/* WARNING: Instruction at (ram,0x00017772) overlaps instruction at (ram,0x00017771)
    */
/* WARNING: Removing unreachable block (ram,0x00017763) */

undefined4 FUN_1000_7700(void)

{
  byte bVar1;
  uint uVar2;
  int in_CX;
  int iVar3;
  int iVar4;
  uint in_DX;
  uint extraout_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar5;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  uVar2 = 0;
  do {
    if (in_BX != unaff_SI) {
      bVar5 = CARRY2(uVar2,*(uint *)(unaff_SI + 8));
      uVar2 = uVar2 + *(uint *)(unaff_SI + 8);
      in_DX = in_DX + *(int *)(unaff_SI + 10) + (uint)bVar5;
    }
    unaff_SI = unaff_SI + 0x16;
    in_CX = in_CX + -1;
  } while (in_CX != 0);
  if (*(uint *)(in_BX + 10) < in_DX) {
LAB_1000_773a_1:
    if ((*(uint *)0x3bc6 & 1) == 0) goto LAB_1000_7771_1;
    *(uint *)0x3bc6 = *(uint *)0x3bc6 & 0xfffe;
    func_0x0001dc56();
  }
  else {
    if (*(uint *)(in_BX + 10) <= in_DX) {
      if (*(uint *)(in_BX + 8) < uVar2) goto LAB_1000_773a_1;
      if (*(uint *)(in_BX + 8) <= uVar2) {
        return CONCAT22(in_DX,uVar2);
      }
    }
    in_DX = (in_DX * 2 + (uint)CARRY2(uVar2,uVar2)) * 2 + (uint)CARRY2(uVar2 * 2,uVar2 * 2);
    *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) | (byte)in_DX;
    if ((*(uint *)(in_BX + 10) <= in_DX) &&
       ((*(uint *)(in_BX + 10) < in_DX || (*(uint *)(in_BX + 8) <= uVar2 * 4))))
    goto LAB_1000_7771_1;
  }
  FUN_1000_2f08();
  func_0x0001dc75();
  in_DX = extraout_DX;
LAB_1000_7771_1:
  iVar3 = 3;
  do {
    iVar4 = 3;
    do {
      FUN_1000_6ab8(iVar3,in_DX);
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
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    in_DX = (uint)(byte)((char)in_DX + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return CONCAT22(in_stack_0000000a,in_stack_0000000e);
}


