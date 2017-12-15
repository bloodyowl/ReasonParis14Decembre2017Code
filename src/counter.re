type action =
  | Increment(int)
  | Decrement(int)
  | Reset;

type state = int;

[@bs.val] external alert : string => unit = "";

let component = ReasonReact.reducerComponent("Counter");

let make = (~onReset, _) => {
  ...component,
  initialState: () => 0,
  reducer: (action, state) =>
    switch action {
    | Increment(n) => ReasonReact.Update(state + n)
    | Decrement(n) => ReasonReact.Update(state - n)
    | Reset => ReasonReact.UpdateWithSideEffects(0, ((_) => onReset()))
    },
  render: ({reduce, state}) =>
    <div>
      <div> (ReasonReact.stringToElement(string_of_int(state))) </div>
      <button onClick=(reduce((_) => Increment(1)))> (ReasonReact.stringToElement("+")) </button>
      <button onClick=(reduce((_) => Increment(2)))> (ReasonReact.stringToElement("+2")) </button>
      <button onClick=(reduce((_) => Decrement(1)))> (ReasonReact.stringToElement("-")) </button>
      <button onClick=(reduce((_) => Reset))> (ReasonReact.stringToElement("reset")) </button>
    </div>
};
