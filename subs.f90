subroutine get_copy(a,b)
character*1 :: a(3,3), b(3,3)
b = a 
return
end subroutine

subroutine get_initboard(a)
character*1 :: a(3,3)
a = reshape((/'1','2','3','4','5','6','7','8','9'/),shape(a))
return
end subroutine



