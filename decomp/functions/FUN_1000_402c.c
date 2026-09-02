/* 1000:402c */

/* WARNING: Instruction at (ram,0x00014053) overlaps instruction at (ram,0x00014052)
    */
/* WARNING: Control flow encountered bad instruction data */

int FUN_1000_402c(void)

{
  uint *puVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  char cVar4;
  uint uVar5;
  byte bVar6;
  undefined2 in_AX;
  undefined2 uVar8;
  int iVar9;
  byte in_CL;
  int iVar10;
  uint in_DX;
  uint extraout_DX;
  int in_BX;
  int unaff_BP;
  uint *unaff_SI;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined2 in_FS;
  bool in_CF;
  bool bVar11;
  byte in_AF;
  bool in_ZF;
  undefined4 uVar12;
  uint uVar7;
  
  if (in_CF || in_ZF) {
    unaff_DI[unaff_BP + -0x73c2] = unaff_DI[unaff_BP + -0x73c2] ^ in_CL;
    bVar6 = (byte)in_AX ^ unaff_DI[unaff_BP + -1];
    uVar7 = CONCAT11((char)((uint)in_AX >> 8),bVar6);
    if (bVar6 == 0) goto LAB_1000_4056;
    FUN_1000_7ccc();
    bVar6 = unaff_DI < (undefined1 *)*(uint *)0xc4ee;
    in_DX = extraout_DX;
  }
  else {
    bVar6 = 9 < ((byte)in_AX & 0xf) | in_AF;
    in_AF = bVar6;
  }
  *(char *)0x3f30 = *(char *)0x3f30 + (char)in_DX + bVar6;
  unaff_DI = (undefined1 *)0xcb1;
  uVar12 = FUN_1000_6bfc();
  in_DX = (uint)((ulong)uVar12 >> 0x10);
  uVar7 = (uint)uVar12;
LAB_1000_4056:
  uVar7 = CONCAT11((char)(uVar7 + 0x3eb2 >> 8),(char)(uVar7 + 0x3eb2) + -0x15 + (uVar7 < 0xc14e));
  do {
    unaff_BP = unaff_BP + uVar7;
    bVar6 = (byte)((uint)in_BX >> 8);
    if ((char)(bVar6 + 0x18) < '\0') {
      puVar2 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      uVar3 = in(in_DX);
      *puVar2 = uVar3;
      unaff_DI[unaff_BP] = unaff_DI[unaff_BP] + (char)(uVar7 >> 8) + (bVar6 < 0xe8);
      in_DX = CONCAT11((byte)(in_DX >> 8) | unaff_DI[unaff_BP],(char)in_DX);
      if ((uVar7 & 0x40) != 0) {
        *unaff_SI = *unaff_SI & uVar7;
        uVar8 = func_0x0001adcd();
        *(undefined2 *)(unaff_BP + -8) = uVar8;
        *(undefined2 *)(unaff_BP + -6) = 0xc792;
        *(undefined2 *)(unaff_BP + -4) = 0;
        *(undefined2 *)(unaff_BP + -2) = 0xa0d;
        iVar10 = 4;
        do {
                    /* WARNING: Call to offcut address within same function */
          iVar9 = func_0x000140e3();
          *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
          *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 0x1900;
          puVar1 = (uint *)(unaff_BP + -6);
          uVar7 = *puVar1;
          *puVar1 = *puVar1 + 0x16;
          iVar10 = iVar10 + -1;
        } while (iVar10 != 0);
        *(undefined2 *)0x328e = 0xffff;
        if ((*(uint *)*(undefined2 *)(unaff_BP + -6) & 8) != 0) {
          return (iVar9 + -0x481b) - (uint)(0xffe9 < uVar7);
        }
        *(undefined2 *)0x1aa3 = (uint *)*(undefined2 *)(unaff_BP + -6);
        FUN_1000_3c94(0);
        iVar10 = 0;
        bVar6 = *(byte *)(unaff_BP + -4);
        if (bVar6 == (byte)unaff_SI[6]) {
          (*(code *)*unaff_SI)();
                    /* WARNING: Could not recover jumptable at 0x0001411d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          iVar10 = (*(code *)(ulong)*(uint *)(iVar10 + (int)unaff_SI))();
          return iVar10;
        }
        *(undefined2 *)0x1a9b = 0;
        *(undefined1 *)0x1aa5 = 0;
        *(undefined2 *)0x1a9d = 0;
        *(undefined2 *)0x1a9f = 0;
        *(char *)0x43a = *(char *)0x43a + (0xf7 < bVar6);
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      unaff_BP = -0x61d0;
      in_AF = 9 < ((byte)uVar7 & 0xf) | in_AF;
      bVar6 = (byte)uVar7 + in_AF * '\x06';
      unaff_SI = (uint *)((int)unaff_SI + 1);
      cVar4 = *(char *)(in_BX + 0x12);
      uVar7 = CONCAT11(cVar4,bVar6) & 0xff0f;
      if ((bVar6 & 4) == 0) {
        if ((bVar6 & 8) != 0) goto FUN_1000_4086;
        goto LAB_1000_4056;
      }
      uVar7 = CONCAT11(cVar4,bVar6) & 0xff0f;
      if (cVar4 == '\0') goto LAB_1000_4056;
      uVar7 = CONCAT11(cVar4 + -1,bVar6) & 0xff0f;
    }
    else {
FUN_1000_4086:
      bVar6 = (byte)(uVar7 >> 8);
      if (0x1d < bVar6) goto LAB_1000_4056;
      uVar7 = CONCAT11(bVar6 + 1,(char)uVar7);
    }
    *(undefined1 *)(in_BX + 0x12) = (char)(uVar7 >> 8);
    unaff_DI = unaff_DI + 2;
    bVar11 = in_DX < *(uint *)(unaff_DI + unaff_BP + 0x2d);
    in_DX = in_DX - *(uint *)(unaff_DI + unaff_BP + 0x2d);
    unaff_SI = (uint *)((int)unaff_SI + 1);
    uVar5 = *unaff_SI;
    *unaff_SI = uVar5 << 0xb | (uint)(CONCAT12(bVar11,uVar5) >> 6);
  } while( true );
}


