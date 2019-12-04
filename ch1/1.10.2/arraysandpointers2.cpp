int main() {
  int int_array_on_stack[10];
  int *int_array_on_heap = new int[10];
}

/*
$ g++ -g -O0 arrayandpointers2.cpp
$ valgrind --tool=memcheck --leak-check=full ./a.out

==14687== Memcheck, a memory error detector
==14687== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==14687== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==14687== Command: ./a.out
==14687==
==14687==
==14687== HEAP SUMMARY:
==14687==     in use at exit: 40 bytes in 1 blocks
==14687==   total heap usage: 2 allocs, 1 frees, 72,744 bytes allocated
==14687==
==14687== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==14687==    at 0x483650F: operator new[](unsigned long)
(vg_replace_malloc.c:423)
==14687==    by 0x109146: main (arrayandpointers2.cpp:3)
==14687==
==14687== LEAK SUMMARY:
==14687==    definitely lost: 40 bytes in 1 blocks
==14687==    indirectly lost: 0 bytes in 0 blocks
==14687==      possibly lost: 0 bytes in 0 blocks
==14687==    still reachable: 0 bytes in 0 blocks
==14687==         suppressed: 0 bytes in 0 blocks
==14687==
==14687== For counts of detected and suppressed errors, rerun with: -v
==14687== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
 */
