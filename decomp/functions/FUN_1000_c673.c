/* 1000:c673 */

void __cdecl16near FUN_1000_c673(void)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined2 unaff_DS;
  
  iVar2 = *(int *)0x34da;
  iVar5 = 0;
  iVar4 = 0x30;
  bVar1 = *(byte *)0x34d8;
  do {
    cVar3 = *(char *)(iVar5 + 0x3eba);
    if (cVar3 < '\0') {
      cVar3 = -(char)((uint)(byte)(1 - cVar3) * (uint)bVar1 >> 8);
    }
    else {
      cVar3 = (char)((uint)(byte)(cVar3 + 1) * (uint)bVar1 >> 8);
    }
    *(char *)((int)(undefined2 *)&DAT_0000_3e20 + iVar5) = cVar3 + *(char *)(iVar5 + iVar2);
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


