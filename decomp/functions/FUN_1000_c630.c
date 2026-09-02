/* 1000:c630 */

undefined4 __cdecl16near FUN_1000_c630(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  int iVar3;
  undefined2 in_DX;
  int iVar4;
  int unaff_SI;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  *(int *)0x34da = unaff_SI;
  iVar4 = 0;
  iVar3 = 0x30;
  do {
    *(char *)(iVar4 + 0x3eba) =
         *(char *)((int)(undefined2 *)&DAT_0000_3e20 + iVar4) - *(char *)(iVar4 + unaff_SI);
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined1 *)0x34d8 = 0xff;
  while( true ) {
    *(undefined1 *)0x32d3 = 1;
    if (*(byte *)0x34d8 < *(byte *)0x34d7) break;
    *(char *)0x34d8 = *(byte *)0x34d8 - *(byte *)0x34d7;
    FUN_1000_c673();
    FUN_1000_9aa6();
  }
  puVar5 = (undefined2 *)*(undefined2 *)0x34da;
  puVar6 = (undefined2 *)&DAT_0000_3e20;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar2 = puVar6;
    puVar6 = puVar6 + 1;
    puVar1 = puVar5;
    puVar5 = puVar5 + 1;
    *puVar2 = *puVar1;
  }
  return CONCAT22(in_DX,in_AX);
}


