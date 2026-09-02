/* 1000:bc99 */

int __cdecl16near FUN_1000_bc99(void)

{
  undefined2 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined2 unaff_DS;
  
  puVar5 = (undefined2 *)&DAT_0000_d27e;
  iVar4 = 0;
  iVar3 = 0x900;
  do {
    puVar1 = puVar5;
    puVar5 = puVar5 + 1;
    cVar2 = (char)*puVar1;
    if ((((cVar2 == '\0') || (cVar2 == '{')) || ((byte)(cVar2 - 8U) < 4)) ||
       (((byte)(cVar2 - 0xcU) < 4 || ((byte)(cVar2 - 1U) < 4)))) {
      iVar4 = iVar4 + 1;
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar4;
}


