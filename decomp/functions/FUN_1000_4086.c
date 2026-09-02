/* 1000:4086 */

/* WARNING: Instruction at (ram,0x00014056) overlaps instruction at (ram,0x00014054)
    */
/* WARNING: Control flow encountered bad instruction data */

int FUN_1000_4086(void)

{
  uint *puVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  char cVar4;
  uint uVar5;
  uint in_AX;
  byte bVar8;
  undefined2 uVar6;
  int iVar7;
  int iVar9;
  uint in_DX;
  int in_BX;
  int unaff_BP;
  uint *puVar10;
  uint *puVar11;
  uint *unaff_SI;
  undefined1 *puVar12;
  undefined1 *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar13;
  byte in_AF;
  
code_r0x00014086:
  puVar11 = unaff_SI;
  bVar8 = (byte)(in_AX >> 8);
  if (0x1d < bVar8) goto LAB_1000_4056;
  in_AX = CONCAT11(bVar8 + 1,(char)in_AX);
LAB_1000_408f:
  *(undefined1 *)(in_BX + 0x12) = (char)(in_AX >> 8);
  puVar10 = puVar11;
  puVar12 = unaff_DI;
  do {
    unaff_DI = puVar12 + 2;
    puVar11 = puVar10 + 1;
    bVar13 = in_DX < *(uint *)(unaff_DI + unaff_BP + 0x2d);
    in_DX = in_DX - *(uint *)(unaff_DI + unaff_BP + 0x2d);
    unaff_SI = (uint *)((int)puVar10 + 1);
    uVar5 = *unaff_SI;
    *unaff_SI = uVar5 << 0xb | (uint)(CONCAT12(bVar13,uVar5) >> 6);
    unaff_BP = unaff_BP + in_AX;
    bVar8 = (byte)((uint)in_BX >> 8);
    if (-1 < (char)(bVar8 + 0x18)) goto code_r0x00014086;
    puVar2 = unaff_DI;
    unaff_DI = puVar12 + 3;
    uVar3 = in(in_DX);
    *puVar2 = uVar3;
    unaff_DI[unaff_BP] = unaff_DI[unaff_BP] + (char)(in_AX >> 8) + (bVar8 < 0xe8);
    in_DX = CONCAT11((byte)(in_DX >> 8) | unaff_DI[unaff_BP],(char)in_DX);
    if ((in_AX & 0x40) != 0) {
      *unaff_SI = *unaff_SI & in_AX;
      uVar6 = func_0x0001adcd();
      *(undefined2 *)(unaff_BP + -8) = uVar6;
      *(undefined2 *)(unaff_BP + -6) = 0xc792;
      *(undefined2 *)(unaff_BP + -4) = 0;
      *(undefined2 *)(unaff_BP + -2) = 0xa0d;
      iVar9 = 4;
      do {
                    /* WARNING: Call to offcut address within same function */
        iVar7 = func_0x000140e3();
        *(int *)(unaff_BP + -4) = *(int *)(unaff_BP + -4) + 1;
        *(int *)(unaff_BP + -2) = *(int *)(unaff_BP + -2) + 0x1900;
        puVar1 = (uint *)(unaff_BP + -6);
        uVar5 = *puVar1;
        *puVar1 = *puVar1 + 0x16;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      *(undefined2 *)0x328e = 0xffff;
      if ((*(uint *)*(undefined2 *)(unaff_BP + -6) & 8) != 0) {
        return (iVar7 + -0x481b) - (uint)(0xffe9 < uVar5);
      }
      *(undefined2 *)0x1aa3 = (uint *)*(undefined2 *)(unaff_BP + -6);
      FUN_1000_3c94(0);
      iVar9 = 0;
      bVar8 = *(byte *)(unaff_BP + -4);
      if (bVar8 == *(byte *)((int)puVar10 + 0xd)) {
        (*(code *)*unaff_SI)();
                    /* WARNING: Could not recover jumptable at 0x0001411d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar9 = (*(code *)(ulong)*(uint *)(iVar9 + (int)unaff_SI))();
        return iVar9;
      }
      *(undefined2 *)0x1a9b = 0;
      *(undefined1 *)0x1aa5 = 0;
      *(undefined2 *)0x1a9d = 0;
      *(undefined2 *)0x1a9f = 0;
      *(char *)0x43a = *(char *)0x43a + (0xf7 < bVar8);
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    unaff_BP = -0x61d0;
    in_AF = 9 < ((byte)in_AX & 0xf) | in_AF;
    bVar8 = (byte)in_AX + in_AF * '\x06';
    cVar4 = *(char *)(in_BX + 0x12);
    in_AX = CONCAT11(cVar4,bVar8) & 0xff0f;
    if ((bVar8 & 4) == 0) {
      unaff_SI = puVar11;
      if ((bVar8 & 8) != 0) goto code_r0x00014086;
    }
    else {
      in_AX = CONCAT11(cVar4,bVar8) & 0xff0f;
      if (cVar4 != '\0') break;
    }
LAB_1000_4056:
    in_AX = CONCAT11((char)(in_AX + 0x3eb2 >> 8),(char)(in_AX + 0x3eb2) + -0x15 + (in_AX < 0xc14e));
    puVar10 = puVar11;
    puVar12 = unaff_DI;
  } while( true );
  in_AX = CONCAT11(cVar4 + -1,bVar8) & 0xff0f;
  goto LAB_1000_408f;
}


