/* 1000:7685 */

/* WARNING: Instruction at (ram,0x000176a9) overlaps instruction at (ram,0x000176a8)
    */

undefined4 FUN_1000_7685(void)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  uint uVar4;
  byte bVar5;
  undefined2 in_AX;
  char cVar7;
  uint uVar6;
  byte bVar8;
  int in_CX;
  uint in_DX;
  uint in_BX;
  int unaff_BP;
  byte *unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar9;
  int in_stack_00000000;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  do {
    in_BX = in_BX & 0xff;
    bVar5 = (byte)in_AX;
    cVar7 = (char)((uint)in_AX >> 8);
    bVar8 = (byte)in_CX;
    if (((byte)*unaff_DI & bVar5) != 0) {
      uVar6 = CONCAT11(cVar7,bVar5 & *unaff_SI);
      pcVar1 = (char *)((int)unaff_DI + unaff_BP + 0x845);
      *pcVar1 = *pcVar1 + bVar8;
code_r0x000176ad:
      uVar4 = unaff_DI[5];
      bVar9 = false;
      if ((uVar6 | uVar4) == 0) {
        puVar2 = unaff_DI;
        *puVar2 = *puVar2 | 4;
        bVar9 = *puVar2 == 0;
        *(undefined1 *)((int)unaff_DI + 0x15) = 4;
      }
      if (bVar9) {
        if ((*(byte *)0x3be8 & (byte)(uVar6 | uVar4)) == 0) {
          piVar3 = (int *)0x3bcc;
          *piVar3 = *piVar3 + 1;
          if (*piVar3 == 0) {
            *(undefined2 *)0x3bcc = 0xffff;
          }
          if (*(int *)0x3bca != 0) {
            *(int *)0x3bca = *(int *)0x3bca + -1;
          }
        }
        return CONCAT22(in_DX,in_stack_00000000);
      }
LAB_1000_76bd:
      return CONCAT22(in_stack_0000000a,in_stack_0000000e);
    }
    if ((unaff_DI[5] & 0x20) != 0) goto LAB_1000_76bd;
    *unaff_SI = *unaff_SI + bVar5;
    unaff_SI[in_stack_00000000] = unaff_SI[in_stack_00000000] ^ bVar8;
    in_DX = unaff_DI[3];
    *(int *)(in_BX + 0x2c) = *(int *)(in_BX + 0x2c) + in_DX;
    unaff_SI[in_stack_00000000] = unaff_SI[in_stack_00000000] ^ bVar8;
    if (in_CX == 1) {
      out(*(undefined2 *)unaff_SI,in_DX);
      unaff_SI[in_stack_00000000 + 2] =
           unaff_SI[in_stack_00000000 + 2] + cVar7 + ((uint *)0xffef < unaff_DI);
      uVar6 = unaff_DI[0xc];
      unaff_DI = unaff_DI + 8;
      goto code_r0x000176ad;
    }
    in_CX = 0x40;
    in_AX = CONCAT11(cVar7,0x80);
    unaff_BP = in_stack_00000000;
    unaff_DI = unaff_DI + 8;
  } while( true );
}


