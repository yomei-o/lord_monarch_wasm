/* 1000:35d3 */

/* WARNING: Instruction at (ram,0x00013639) overlaps instruction at (ram,0x00013638)
    */
/* WARNING: Control flow encountered bad instruction data */

undefined2 FUN_1000_35d3(undefined2 param_1)

{
  uint *puVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  byte bVar5;
  byte bVar6;
  code *pcVar7;
  uint in_AX;
  undefined2 uVar8;
  uint in_CX;
  int in_DX;
  int in_BX;
  int unaff_BP;
  undefined2 *unaff_SI;
  undefined2 *unaff_DI;
  undefined2 *puVar9;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar10;
  undefined2 *in_stack_00000000;
  
  *(uint *)(in_BX + (int)unaff_SI) = *(uint *)(in_BX + (int)unaff_SI) ^ in_DX - 1U;
  bVar10 = CARRY2(in_AX,in_AX);
  FUN_1000_a09a();
  if (!bVar10) {
    puVar1 = (uint *)(unaff_BP + (int)unaff_SI);
    *puVar1 = *puVar1 << 0xd | *puVar1 >> 3;
    uVar8 = FUN_1000_8f9d();
    unaff_SI[-0xbcd] = unaff_SI[-0xbcd] & in_CX;
    return uVar8;
  }
  pbVar4 = (byte *)(unaff_SI + 1);
  *unaff_DI = *unaff_SI;
  puVar9 = unaff_DI + 1;
  if (((char)in_CX != (char)in_stack_00000000) &&
     ((char)in_CX != (char)((uint)in_stack_00000000 >> 8))) {
    bVar5 = *(byte *)(in_BX + -0x2d81);
    in_stack_00000000 = (undefined2 *)unaff_SI[4];
    puVar1 = unaff_SI + 4;
    uVar3 = *puVar1;
    *puVar1 = *puVar1 - (uint)bVar5;
    if (bVar5 <= uVar3 && *puVar1 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    FUN_1000_3dc0();
    if ((char)((uint)in_stack_00000000 >> 8) == '\0') {
      pbVar2 = (byte *)(in_BX + -0x2d81);
      bVar5 = *pbVar2;
      *pbVar2 = *pbVar2 - (byte)in_stack_00000000;
      puVar9 = in_stack_00000000;
      if ((byte)in_stack_00000000 <= bVar5 && *pbVar2 != 0) goto LAB_1000_3652;
    }
    return param_1;
  }
LAB_1000_3652:
  bVar10 = CARRY1(*(byte *)((int)puVar9 + 0x1451),*pbVar4);
  pbVar2 = pbVar4 + unaff_BP;
  bVar5 = *pbVar2;
  bVar6 = *pbVar2 + (byte)in_stack_00000000;
  *pbVar2 = bVar6 + bVar10;
  pbVar4[unaff_BP] =
       pbVar4[unaff_BP] + (char)unaff_SS +
       (in_stack_00000000 < *(undefined2 **)(pbVar4 + unaff_BP) ||
       (uint)((int)in_stack_00000000 - *(int *)(pbVar4 + unaff_BP)) <
       (uint)(CARRY1(bVar5,(byte)in_stack_00000000) || CARRY1(bVar6,bVar10)));
  pcVar7 = (code *)swi(3);
  uVar8 = (*pcVar7)(&stack0x0000);
  return uVar8;
}


