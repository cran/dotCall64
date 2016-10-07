      subroutine get_f(input, index, output)
      double precision :: input(*), output(*)
      integer :: index
      output(1) = input(index)
      end

      subroutine get64_f(input, index, output)
      double precision :: input(*), output(*)
      integer (kind = 8) :: index  ! 64-bit integer on GFortran, differs with other compilers   
      output(1) = input(index)
      end

