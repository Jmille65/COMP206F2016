let multByTwo x =
  x*2

let multbyThree x =
  x*3

let funcList = [multByTwo;multbyThree]

let rec applyToList l f =
  match l with
    | [] -> []
    | x::xs -> f(x)::applyToList xs f

applyToList [1;2;3] multByTwo

let rec buildFunc lf =
  match lf with
    | [] ->
      fun x -> x
    | f::fs ->
      fun x -> f ((buildFunc fs) x)



applyToList [1;2;3] (buildFunc funcList)
