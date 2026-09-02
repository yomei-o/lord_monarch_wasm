/* 1000:9239 */

undefined4 __cdecl16near FUN_1000_9239(void)

{
  undefined2 uVar1;
  undefined2 in_CX;
  int iVar2;
  int extraout_DX;
  int extraout_DX_00;
  undefined2 *puVar3;
  int iVar4;
  uint *unaff_SI;
  char *unaff_DI;
  undefined2 *puVar5;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  undefined2 uVar6;
  
  puVar3 = (undefined2 *)
           (((uint)(byte)(((char)*unaff_SI + *unaff_DI) - unaff_DI[1]) * 0x280 + (*unaff_SI >> 8)) *
            2 + 0x50d);
  iVar4 = 0x10;
  do {
    uVar6 = 0x926e;
    FUN_1000_7262();
    iVar2 = extraout_DX;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_1000_724a(uVar6);
    iVar2 = extraout_DX_00;
    do {
      puVar5 = puVar3;
      puVar3 = puVar5 + -1;
      *puVar3 = uVar1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    puVar3 = puVar5 + 0x27;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  out(0x7c,0);
  return CONCAT22(in_CX,unaff_ES);
}


