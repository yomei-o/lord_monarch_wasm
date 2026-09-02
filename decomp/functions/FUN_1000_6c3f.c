/* 1000:6c3f */

undefined4 __cdecl16near FUN_1000_6c3f(void)

{
  undefined2 in_AX;
  undefined2 in_DX;
  undefined *puVar1;
  undefined *puVar2;
  undefined2 unaff_DS;
  
  *(char *)&DAT_0000_3e80 = (char)in_AX;
  puVar2 = (undefined *)&DAT_0000_818e;
  puVar1 = (undefined *)&DAT_0000_798e;
  if ((char)in_AX != '\0') {
    puVar2 = (undefined *)&DAT_0000_a18e;
    puVar1 = (undefined *)&DAT_0000_998e;
  }
  *(undefined2 *)0x3e82 = puVar2;
  *(undefined2 *)0x3e84 = unaff_DS;
  *(undefined2 *)0x3e86 = puVar1;
  *(undefined2 *)0x3e88 = unaff_DS;
  return CONCAT22(in_DX,in_AX);
}


