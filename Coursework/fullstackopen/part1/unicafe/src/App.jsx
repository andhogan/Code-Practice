import { useState } from 'react'

const Header = ({ text }) => <h1>{text}</h1>

const Display = ({ text, counter }) => <div>{text} {counter}</div>

const Button = ({ onClick, text }) => <button onClick={onClick}>{text}</button>

const App = () => {
  // save clicks of each button to its own state
  const [good, setGood] = useState(0)
  const [neutral, setNeutral] = useState(0)
  const [bad, setBad] = useState(0)
  let all = good+neutral+bad
  let average = (good-bad)/(all)
  let positive = ((good/all) * 100).toString() + ' %'

  const increaseGoodByOne = () => setGood(good + 1)
  const increaseNeutralByOne = () => setNeutral(neutral + 1)
  const increaseBadByOne = () => setBad(bad + 1)
  const resetToZero = () => {
    setGood(0)
    setNeutral(0)
    setBad(0)
  }

  return (
    <div>
      <Header text='give feedback'/>
      <Button onClick={increaseGoodByOne} text='good'/>
      <Button onClick={increaseNeutralByOne} text='neutral'/>
      <Button onClick={increaseBadByOne} text='bad'/>
      <Button onClick={resetToZero} text='reset'/>
      <Header text='statistics'/>
      <Display text='good' counter={good} />
      <Display text='neutral' counter={neutral} />
      <Display text='bad' counter={bad} />
      <Display text='all' counter={good+neutral+bad} />
      <Display text='average' counter={average} />
      <Display text='positive' counter={positive} />
    </div>
  )
}

export default App