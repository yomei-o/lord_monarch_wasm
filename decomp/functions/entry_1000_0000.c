/* 1000:0000 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00010058) overlaps instruction at (ram,0x00010056)
    */

void entry_1000_0000(void)

{
  byte bVar1;
  int in_CX;
  undefined2 unaff_ES;
  undefined2 unaff_CS;
  undefined2 unaff_DS;
  
  if (in_CX == 0) {
    *(undefined2 *)&DAT_0000_3e7e = unaff_ES;
  }
  else {
    unaff_DS = 0;
    DAT_0000_3c1c = (undefined2)((ulong)uRam0000004c >> 0x10);
    DAT_0000_3c1a = (undefined2)uRam0000004c;
    uRam00000000 = 0x73c;
    uRam00000024 = 0x7e0;
    uRam00000028 = 0x755;
    uRam0000004c = CONCAT22(unaff_CS,0x873);
    uRam00000054 = 0x8b6;
    DAT_0000_0ffe = 0;
    DAT_0000_3e7e = (undefined2)((ulong)uRam0000006c >> 0x10);
    DAT_0000_3e7c = (undefined2)uRam0000006c;
    uRam00000002 = unaff_CS;
    uRam00000026 = unaff_CS;
    uRam0000002a = unaff_CS;
    uRam00000056 = unaff_CS;
  }
  FUN_1000_018c();
  FUN_1000_01be();
  FUN_1000_0250();
  *(undefined1 *)&DAT_0000_32f3 = *(undefined1 *)&DAT_0000_0564;
  *(undefined1 *)&DAT_0000_32f5 = *(undefined1 *)&DAT_0000_056c;
  *(undefined2 *)&DAT_0000_3e80 = 0;
  out(0x68,0xb);
  bVar1 = in(2);
  out(2,bVar1 & 0xf9);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


