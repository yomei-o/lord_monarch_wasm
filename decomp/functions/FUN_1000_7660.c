/* 1000:7660 */

/* WARNING: Instruction at (ram,0x000176a9) overlaps instruction at (ram,0x000176a8)
    */
/* WARNING: Removing unreachable block (ram,0x000176a5) */

undefined4
FUN_1000_7660(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
             undefined2 param_5)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  uint uVar4;
  char cVar5;
  byte bVar6;
  uint in_AX;
  uint uVar7;
  int in_CX;
  uint in_DX;
  uint in_BX;
  int unaff_BP;
  char *unaff_SI;
  uint *unaff_DI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar8;
  
  do {
    uVar7 = in_AX & 0xff00;
    while( true ) {
      uVar7 = uVar7 >> 8;
      in_DX = in_DX + 1;
      puVar2 = (uint *)(in_BX + 8);
      uVar4 = *puVar2;
      *puVar2 = *puVar2 + uVar7;
      if (CARRY2(uVar4,uVar7)) {
        *(int *)(in_BX + 10) = *(int *)(in_BX + 10) + 1;
      }
      in_CX = in_CX + -1;
      if (in_CX == 0) {
        unaff_DI = (uint *)0xc800;
        goto LAB_1000_7680;
      }
      unaff_SI = (char *)0x208b;
      in_AX = *(uint *)0x2089;
      if ((char)in_AX == '\x05') break;
      bVar6 = (char)in_AX - 8;
      uVar7 = CONCAT11((char)(in_AX >> 8),bVar6);
      if (3 < bVar6) goto LAB_1000_7680;
    }
  } while( true );
LAB_1000_7680:
  bVar6 = (byte)(uVar7 >> 8);
  in_BX = in_BX & 0xff;
  if ((*unaff_DI & 0x80) != 0) {
    cVar5 = *unaff_SI;
    pcVar1 = (char *)((int)unaff_DI + unaff_BP + 0x845);
    *pcVar1 = *pcVar1 + '@';
    uVar7 = CONCAT11(bVar6,cVar5) & 0xff80 | unaff_DI[5];
    bVar8 = false;
    if (uVar7 == 0) {
      puVar2 = unaff_DI;
      *puVar2 = *puVar2 | 4;
      bVar8 = *puVar2 == 0;
      *(undefined1 *)((int)unaff_DI + 0x15) = 4;
    }
    if (bVar8) {
      if ((*(byte *)0x3be8 & (byte)uVar7) == 0) {
        piVar3 = (int *)0x3bcc;
        *piVar3 = *piVar3 + 1;
        if (*piVar3 == 0) {
          *(undefined2 *)0x3bcc = 0xffff;
        }
        if (*(int *)0x3bca != 0) {
          *(int *)0x3bca = *(int *)0x3bca + -1;
        }
      }
      return CONCAT22(in_DX,unaff_BP);
    }
LAB_1000_76bd:
    return CONCAT22(param_3,param_5);
  }
  if ((unaff_DI[5] & 0x20) != 0) goto LAB_1000_76bd;
  *unaff_SI = *unaff_SI + -0x80;
  uVar7 = (uint)bVar6 << 8;
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] ^ 0x40;
  in_DX = unaff_DI[3];
  *(int *)(in_BX + 0x2c) = *(int *)(in_BX + 0x2c) + in_DX;
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] ^ 0x40;
  unaff_DI = unaff_DI + 8;
  goto LAB_1000_7680;
}


