/* 1000:bcce */

int __cdecl16near FUN_1000_bcce(void)

{
  char in_AL;
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined2 unaff_DS;
  
  pcVar3 = (char *)&DAT_0000_d27e;
  iVar2 = 0;
  iVar1 = 0x900;
  do {
    if (((char)(in_AL + '\f') == *pcVar3) || ((char)(in_AL + '\b') == *pcVar3)) {
      iVar2 = iVar2 + 1;
    }
    pcVar3 = pcVar3 + 2;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return iVar2;
}


