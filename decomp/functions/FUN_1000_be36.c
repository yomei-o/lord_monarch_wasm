/* 1000:be36 */

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl16near FUN_1000_be36(void)

{
  byte bVar1;
  uint in_CX;
  undefined1 extraout_DL;
  uint in_DX;
  char cVar3;
  undefined2 uVar2;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 extraout_DX_01;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  uint *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  bool bVar11;
  
  *(undefined2 *)0x32bb = 0xffff;
  *(undefined1 **)0xc4ec = &stack0xffec;
  *(undefined2 *)&DAT_0000_c4ea = unaff_SS;
  puVar9 = (undefined1 *)0x0;
  uVar10 = (in_DX >> 8) * 0x60;
  iVar5 = (in_DX & 0xff) * 2;
  piRam0002fffe = (int *)((undefined *)&DAT_0000_ffa0 + uVar10 + iVar5);
  bVar11 = true;
  LOCK();
  iRam0002fffc = *piRam0002fffe;
  *piRam0002fffe = 0;
  UNLOCK();
  uRam0002fffa = 0xbe78;
  FUN_1000_bf41();
  *piRam0002fffe = iRam0002fffc;
  if (!bVar11) {
    in_CX = in_CX & 0xff;
    piRam0002fffe = (int *)0xbe86;
    FUN_1000_c050();
    cVar3 = (char)in_CX + (char)(in_CX >> 8);
    piRam0002fffe = (int *)CONCAT11(cVar3,extraout_DL);
    uVar2 = CONCAT11(cVar3,0xa0);
    puVar8 = (undefined1 *)0xfffa;
    uRam0002fffa = uVar10;
    iRam0002fffc = iVar5;
LAB_1000_be8f:
    do {
      uVar10 = uVar10 + (int)(char)uVar2;
      if (((int)uVar10 < 0) || (bVar11 = uVar10 == 0x1200, 0x11ff < uVar10)) goto LAB_1000_bf1c;
      in_CX = CONCAT11((char)((uint)uVar2 >> 8),(char)in_CX);
      *(undefined2 *)(puVar8 + -2) = 0xbea4;
      FUN_1000_bf41();
      if (bVar11) goto LAB_1000_bf1c;
      uVar4 = in_CX >> 8;
      in_CX = in_CX & 0xff;
      uVar2 = extraout_DX;
      if ((char)((uint)extraout_DX >> 8) == (char)uVar4) {
        *(undefined2 *)(puVar8 + -2) = 0xbeaf;
        FUN_1000_c050();
        uVar2 = extraout_DX_00;
      }
      if (puVar8 < (undefined1 *)0x6040) break;
      bVar1 = (byte)(in_CX >> 8);
      *(uint *)(puVar8 + -2) = CONCAT11((char)in_CX + bVar1,(char)uVar2);
      *(int *)(puVar8 + -4) = iVar5;
      puVar6 = puVar8 + -6;
      *(uint *)(puVar8 + -6) = uVar10;
      if (bVar1 < 2) goto LAB_1000_bed4;
      if (puVar8 + -6 < (undefined1 *)0x6040) break;
      *(uint *)(puVar8 + -8) = CONCAT11(bVar1 - 1,-(char)uVar2);
      *(int *)(puVar8 + -10) = iVar5;
      puVar6 = puVar8 + -0xc;
      *(uint *)(puVar8 + -0xc) = uVar10;
LAB_1000_bed4:
      while( true ) {
        cVar3 = (char)((uint)uVar2 >> 8);
        bVar1 = ((char)in_CX - cVar3) + 1;
        puVar8 = puVar6;
        if (bVar1 < 3) break;
        if (-1 < (char)bVar1) {
          cVar3 = cVar3 + '\x01';
          iVar5 = _DAT_2000_4400 + cVar3 * 2;
          uVar2 = CONCAT11(-(cVar3 - (char)in_CX),-(char)uVar2);
          goto LAB_1000_be8f;
        }
        uVar4 = _DAT_2000_4402 + 2;
        bVar11 = uVar4 == 0x60;
        if (0x5f < uVar4) break;
        *(undefined2 *)(puVar6 + -2) = 0xbef5;
        FUN_1000_bf41();
        if (bVar11) break;
        if (puVar6 < (undefined1 *)0x6040) goto LAB_1000_bf2f;
        *(uint *)(puVar6 + -2) = CONCAT11((char)in_CX,(char)extraout_DX_01);
        *(uint *)(puVar6 + -4) = uVar4;
        puVar7 = (uint *)(puVar6 + -6);
        puVar6 = puVar6 + -6;
        *puVar7 = uVar10;
        uVar2 = extraout_DX_01;
      }
LAB_1000_bf1c:
      if (puVar8 == puVar9) break;
      uVar2 = *(undefined2 *)(puVar9 + -2);
      iVar5 = *(int *)(puVar9 + -4);
      uVar10 = *(uint *)(puVar9 + -6);
      puVar9 = puVar9 + -6;
    } while( true );
  }
LAB_1000_bf2f:
  return CONCAT22(*(undefined2 *)(DAT_0000_c4ec + 10),*(undefined2 *)(DAT_0000_c4ec + 0xe));
}


