/* 1000:7702 */

/* WARNING: Instruction at (ram,0x00017772) overlaps instruction at (ram,0x00017771)
    */
/* WARNING: Removing unreachable block (ram,0x00017763) */

undefined4 FUN_1000_7702(void)

{
  byte bVar1;
  uint in_AX;
  int in_CX;
  int iVar2;
  int iVar3;
  uint in_DX;
  uint extraout_DX;
  int in_BX;
  int unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar4;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  do {
    if (in_BX != unaff_SI) {
      bVar4 = CARRY2(in_AX,*(uint *)(unaff_SI + 8));
      in_AX = in_AX + *(uint *)(unaff_SI + 8);
      in_DX = in_DX + *(int *)(unaff_SI + 10) + (uint)bVar4;
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
      if (*(uint *)(in_BX + 8) < in_AX) goto LAB_1000_773a_1;
      if (*(uint *)(in_BX + 8) <= in_AX) {
        return CONCAT22(in_DX,in_AX);
      }
    }
    in_DX = (in_DX * 2 + (uint)CARRY2(in_AX,in_AX)) * 2 + (uint)CARRY2(in_AX * 2,in_AX * 2);
    *(byte *)(in_BX + unaff_SI) = *(byte *)(in_BX + unaff_SI) | (byte)in_DX;
    if ((*(uint *)(in_BX + 10) <= in_DX) &&
       ((*(uint *)(in_BX + 10) < in_DX || (*(uint *)(in_BX + 8) <= in_AX * 4))))
    goto LAB_1000_7771_1;
  }
  FUN_1000_2f08();
  func_0x0001dc75();
  in_DX = extraout_DX;
LAB_1000_7771_1:
  iVar2 = 3;
  do {
    iVar3 = 3;
    do {
      FUN_1000_6ab8(iVar2,in_DX);
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
    in_DX = (uint)(byte)((char)in_DX + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return CONCAT22(in_stack_0000000a,in_stack_0000000e);
}


