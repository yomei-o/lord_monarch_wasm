/* 1000:1371 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1000_1371(void)

{
  undefined2 in_AX;
  
  out(0x71,(char)((uint)in_AX >> 8));
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


