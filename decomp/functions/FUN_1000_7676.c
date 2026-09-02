/* 1000:7676 */

/* WARNING: Instruction at (ram,0x000176a9) overlaps instruction at (ram,0x000176a8)
    */
/* WARNING: Removing unreachable block (ram,0x000176a5) */

undefined4 FUN_1000_7676(void)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  char cVar4;
  byte bVar5;
  uint in_AX;
  byte bVar7;
  uint uVar6;
  int in_CX;
  uint in_DX;
  uint in_BX;
  int unaff_BP;
  char *unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined1 in_CF;
  bool bVar8;
  int in_stack_00000000;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  
  while( true ) {
    if ((bool)in_CF) {
      *(int *)(in_BX + 10) = *(int *)(in_BX + 10) + 1;
    }
    in_CX = in_CX + -1;
    if (in_CX == 0) break;
    unaff_SI = (char *)0x208b;
    cVar4 = (char)*(undefined2 *)0x2089;
    bVar7 = (byte)((uint)*(undefined2 *)0x2089 >> 8);
    if (cVar4 == '\x05') {
      in_AX = (uint)bVar7 << 8;
    }
    else {
      bVar5 = cVar4 - 8;
      in_AX = CONCAT11(bVar7,bVar5);
      if (3 < bVar5) goto LAB_1000_7680;
    }
    in_AX = in_AX >> 8;
    in_DX = in_DX + 1;
    puVar2 = (uint *)(in_BX + 8);
    in_CF = CARRY2(*puVar2,in_AX);
    *puVar2 = *puVar2 + in_AX;
    in_stack_00000000 = unaff_BP;
  }
  unaff_DI = (uint *)0xc800;
LAB_1000_7680:
  do {
    bVar7 = (byte)(in_AX >> 8);
    in_BX = in_BX & 0xff;
    if ((*unaff_DI & 0x80) != 0) {
      cVar4 = *unaff_SI;
      pcVar1 = (char *)((int)unaff_DI + unaff_BP + 0x845);
      *pcVar1 = *pcVar1 + '@';
      uVar6 = CONCAT11(bVar7,cVar4) & 0xff80 | unaff_DI[5];
      bVar8 = false;
      if (uVar6 == 0) {
        puVar2 = unaff_DI;
        *puVar2 = *puVar2 | 4;
        bVar8 = *puVar2 == 0;
        *(undefined1 *)((int)unaff_DI + 0x15) = 4;
      }
      if (bVar8) {
        if ((*(byte *)0x3be8 & (byte)uVar6) == 0) {
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
    *unaff_SI = *unaff_SI + -0x80;
    in_AX = (uint)bVar7 << 8;
    unaff_SI[in_stack_00000000] = unaff_SI[in_stack_00000000] ^ 0x40;
    in_DX = unaff_DI[3];
    *(int *)(in_BX + 0x2c) = *(int *)(in_BX + 0x2c) + in_DX;
    unaff_SI[in_stack_00000000] = unaff_SI[in_stack_00000000] ^ 0x40;
    unaff_DI = unaff_DI + 8;
    unaff_BP = in_stack_00000000;
  } while( true );
}


