/* 1000:7641 */

/* WARNING: Instruction at (ram,0x000176a9) overlaps instruction at (ram,0x000176a8)
    */
/* WARNING: Removing unreachable block (ram,0x000176a5) */

undefined4 FUN_1000_7641(void)

{
  char *pcVar1;
  uint *puVar2;
  int *piVar3;
  uint uVar4;
  undefined1 uVar5;
  char cVar6;
  byte bVar7;
  uint uVar8;
  byte bVar10;
  uint uVar9;
  undefined2 in_CX;
  int iVar11;
  int iVar12;
  uint in_DX;
  uint in_BX;
  int unaff_BP;
  int unaff_SI;
  uint *puVar13;
  undefined2 unaff_SS;
  int unaff_DS;
  bool bVar14;
  
  *(byte *)(unaff_BP + unaff_SI) = *(byte *)(unaff_BP + unaff_SI) & (byte)((uint)in_CX >> 8);
  puVar13 = (uint *)0xc792;
  iVar11 = 5;
  do {
    puVar13[4] = 0;
    puVar13[5] = 0;
    puVar13 = puVar13 + 0xb;
    iVar11 = iVar11 + -1;
    iVar12 = 0;
  } while (iVar11 != 0);
  do {
    cVar6 = (char)*(undefined2 *)0x2089;
    bVar10 = (byte)((uint)*(undefined2 *)0x2089 >> 8);
    uVar9 = in_BX;
    if (cVar6 == '\x05') {
      uVar8 = (uint)bVar10 << 8;
    }
    else {
      bVar7 = cVar6 - 8;
      uVar8 = CONCAT11(bVar10,bVar7);
      if (3 < bVar7) goto LAB_1000_7680;
    }
    uVar8 = uVar8 >> 8;
    in_DX = in_DX + 1;
    puVar2 = (uint *)(in_BX + 8);
    uVar4 = *puVar2;
    *puVar2 = *puVar2 + uVar8;
    if (CARRY2(uVar4,uVar8)) {
      *(int *)(in_BX + 10) = *(int *)(in_BX + 10) + 1;
    }
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  puVar13 = (uint *)0xc800;
LAB_1000_7680:
  do {
    bVar10 = (byte)(uVar8 >> 8);
    if ((*puVar13 & 0x80) != 0) {
      uVar5 = *(undefined1 *)0x208b;
      pcVar1 = (char *)((int)puVar13 + unaff_BP + 0x845);
      *pcVar1 = *pcVar1 + '@';
      uVar9 = CONCAT11(bVar10,uVar5) & 0xff80 | puVar13[5];
      bVar14 = false;
      if (uVar9 == 0) {
        puVar2 = puVar13;
        *puVar2 = *puVar2 | 4;
        bVar14 = *puVar2 == 0;
        *(undefined1 *)((int)puVar13 + 0x15) = 4;
      }
      if (bVar14) {
        if ((*(byte *)0x3be8 & (byte)uVar9) == 0) {
          piVar3 = (int *)0x3bcc;
          *piVar3 = *piVar3 + 1;
          if (*piVar3 == 0) {
            *(undefined2 *)0x3bcc = 0xffff;
          }
          if (*(int *)0x3bca != 0) {
            *(int *)0x3bca = *(int *)0x3bca + -1;
          }
        }
        return CONCAT22(in_DX,unaff_DS);
      }
LAB_1000_76bd:
      return CONCAT22(in_BX,in_CX);
    }
    if ((puVar13[5] & 0x20) != 0) goto LAB_1000_76bd;
    *(char *)0x208b = *(char *)0x208b + -0x80;
    uVar8 = (uint)bVar10 << 8;
    *(byte *)(unaff_DS + 0x208b) = *(byte *)(unaff_DS + 0x208b) ^ 0x40;
    in_DX = puVar13[3];
    piVar3 = (int *)((uVar9 & 0xff) + 0x2c);
    *piVar3 = *piVar3 + in_DX;
    *(byte *)(unaff_DS + 0x208b) = *(byte *)(unaff_DS + 0x208b) ^ 0x40;
    puVar13 = puVar13 + 8;
    uVar9 = uVar9 & 0xff;
    unaff_BP = unaff_DS;
  } while( true );
}


