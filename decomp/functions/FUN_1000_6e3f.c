/* 1000:6e3f */

/* WARNING: Instruction at (ram,0x00016e47) overlaps instruction at (ram,0x00016e44)
    */
/* WARNING: Removing unreachable block (ram,0x00016e58) */

void FUN_1000_6e3f(void)

{
  undefined1 *unaff_SI;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  
  do {
    out(0xa6,*(byte *)0x3482 ^ 1);
    unaff_SI[0x2488] = unaff_SI[0x2488] + '^';
    unaff_SI = &stack0x000c + (int)unaff_SI;
  } while( true );
}


