import { useState } from 'react'

const Header = ({ text }) => <h1>{text}</h1>

const Display = ({ text, counter }) => <div>{text} {counter}</div>

const Button = ({ onClick, text }) => <button onClick={onClick}>{text}</button>

const App = () => {
  // save clicks of each button to its own state
  const [good, setGood] = useState(0)
  const [neutral, setNeutral] = useState(0)
  const [bad, setBad] = useState(0)

  const increaseGoodByOne = () => setGood(good + 1)
  const increaseNeutralByOne = () => setNeutral(neutral + 1)
  const increaseBadByOne = () => setBad(bad + 1)

  return (
    <div>
      <Header text='give feedback'/>
      <Button onClick={increaseGoodByOne} text='good'/>
      <Button onClick={increaseNeutralByOne} text='neutral'/>
      <Button onClick={increaseBadByOne} text='bad'/>
      <Header text='statistics'/>
      <Display text='good' counter={good} />
      <Display text='neutral' counter={neutral} />
      <Display text='bad' counter={bad} />
    </div>
  )
}

export default App