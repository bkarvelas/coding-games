open System

let n = int (Console.In.ReadLine()) (* the number of temperatures to analyse *)

let temperatures = (Console.In.ReadLine()).Split [| ' ' |]

let intTemps =
    match temperatures with
    | [| "" |] -> []
    | _ ->
        temperatures
        |> Array.toList
        |> List.map int

let allNegatives = intTemps |> List.forall (fun x -> x < 0)

let allPositives = intTemps |> List.forall (fun x -> x > 0)

let minPositiveTemp temps =
    temps
    |> List.filter (fun x -> x > 0)
    |> List.min

let maxNegativeTemp temps =
    temps
    |> List.filter (fun x -> x < 0)
    |> List.max

let result temps =
    match temps with
    | [] -> 0
    | _ ->
        match allNegatives, allPositives with
        | aN, _ when aN -> maxNegativeTemp temps
        | _, aP when aP -> minPositiveTemp temps
        | _ ->
            match minPositiveTemp temps, maxNegativeTemp temps with
            | x, y when abs x > abs y -> y
            | x, y when abs x < abs y -> x
            | x, y when abs x = abs y -> abs x
            | _ -> failwith "Oops I did it again..."

printfn "%d" (result intTemps)
