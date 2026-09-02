/* 1000:9946 */

undefined4 __cdecl16near FUN_1000_9946(void)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined2 in_AX;
  int iVar5;
  undefined2 in_DX;
  int iVar6;
  int unaff_SI;
  undefined1 *puVar7;
  undefined1 *unaff_DI;
  undefined2 unaff_SS;
  
  uVar1 = *(undefined2 *)(unaff_SI + 2);
  puVar7 = (undefined1 *)0x0;
  out(0x7c,0xc0);
  iVar6 = *(int *)(unaff_SI + 6);
  iVar4 = *(int *)(unaff_SI + 4);
  do {
    iVar5 = *(int *)(unaff_SI + 4);
    do {
      out(*puVar7,0x7e);
      out(puVar7[1],0x7e);
      out(puVar7[2],0x7e);
      puVar2 = puVar7 + 4;
      out(puVar7[3],0x7e);
      puVar3 = unaff_DI;
      unaff_DI = unaff_DI + 1;
      puVar7 = puVar7 + 5;
      *puVar3 = *puVar2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    unaff_DI = unaff_DI + (0x50 - iVar4);
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  out(0x7c,0);
  return CONCAT22(in_DX,in_AX);
}


