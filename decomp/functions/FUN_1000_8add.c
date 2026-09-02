/* 1000:8add */

/* WARNING: Control flow encountered bad instruction data */

undefined4 FUN_1000_8add(undefined1 *param_1,undefined2 param_2)

{
  byte *pbVar1;
  byte bVar2;
  undefined2 in_AX;
  int in_CX;
  int iVar3;
  undefined2 in_DX;
  uint in_BX;
  byte bVar4;
  int unaff_BP;
  byte *unaff_SI;
  byte *unaff_DI;
  undefined2 unaff_ES;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  int in_stack_00000000;
  
  *(undefined2 *)(unaff_DI + 0x7c) = in_AX;
  while( true ) {
    *unaff_DI = unaff_SI[1] >> 1;
    unaff_SI = unaff_SI + -in_stack_00000000;
    unaff_DI = param_1 + 1;
    *param_1 = 0xa2;
    pbVar1 = unaff_SI + unaff_BP + -0x2f20;
    *pbVar1 = *pbVar1 + (char)in_CX + 1;
    iVar3 = in_CX + -1;
    if (iVar3 == 0 || *pbVar1 == 0) {
      if (in_CX + -2 == 0 || *pbVar1 == 0) {
        bVar4 = (byte)(in_BX >> 8);
        in_BX = CONCAT11(bVar4,(char)in_BX + *(char *)0x2db9);
        pbVar1 = (byte *)((int)*(undefined4 *)unaff_DI + 0xb);
        *pbVar1 = *pbVar1 | bVar4;
      }
      return CONCAT22(*(undefined2 *)unaff_DI,
                      CONCAT11(3,(*(byte *)((in_BX >> 1) + *(int *)((in_BX >> 1) + 0x247e) + 0x2400)
                                  >> ((byte)(in_CX + -2) & 3) * '\x02' & 3) * '\x02'));
    }
    pbVar1 = unaff_SI;
    bVar4 = *pbVar1;
    *pbVar1 = *pbVar1 + 0x57;
    in_stack_00000000 = 0x54a2;
    if (0xa8 < bVar4) break;
    unaff_DI[unaff_BP] = unaff_DI[unaff_BP];
    *(undefined2 *)(param_1 + 0x7f) = 0x54a2;
    *(undefined2 *)(param_1 + 0x7d) = 0x54a3;
    in_CX = iVar3;
    unaff_ES = param_2;
  }
  bVar4 = unaff_SI[in_BX];
  *unaff_DI = unaff_SI[in_BX] + 0xa2;
  param_1[2] = 3;
  unaff_SI[unaff_BP + 0x55] = (unaff_SI[unaff_BP + 0x55] + 0x56) - (0x5d < bVar4);
  unaff_SI[unaff_BP + 0x610] = 0;
  bVar2 = (byte)((uint)in_DX >> 9);
  param_1[3] = 2;
  unaff_SI[unaff_BP] = unaff_SI[unaff_BP] ^ 2;
  bVar4 = unaff_SI[unaff_BP + 0x1610];
  param_1[4] = bVar2;
  if (CONCAT11((byte)((uint)iVar3 >> 8) | bVar4,(char)iVar3) == 1) {
    param_1[4] = bVar2;
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


