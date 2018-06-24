SECTIONS
 {
  . = 0X100000;
  .text :
  {*(.text)}
  .data :
  {
  *(.data)
  }
  .bss : 
  {
  *(.bss)
  }
 }