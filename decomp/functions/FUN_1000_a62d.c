/* 1000:a62d */

undefined2 __cdecl16near FUN_1000_a62d(void)

{
  undefined2 in_AX;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined2 unaff_ES;
  undefined2 unaff_DS;
  
  pcVar2 = (char *)&DAT_0000_d27e;
  iVar1 = 0x900;
  do {
    pcVar3 = pcVar2 + 1;
    if ((char)(*(char *)0x3c00 + '\x14') == *pcVar2) break;
    pcVar2 = pcVar2 + 2;
    iVar1 = iVar1 + -1;
    pcVar3 = pcVar2;
  } while (iVar1 != 0);
  *(undefined2 *)&DAT_0000_3be4 =
       CONCAT11((char)(((uint)(pcVar3 + 0x2d81) >> 1) / 0x30),
                (char)(((uint)(pcVar3 + 0x2d81) >> 1) % 0x30));
  return in_AX;
}


