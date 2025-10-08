import { useState } from 'react'

const Header = ({ text }) => <h1>{text}</h1>

const StatisticsLine = ({ text, counter }) => {
  return(
    <tr>
      <td>{text}</td>
      <td>{counter}</td>
    </tr>
  )
}

const Statistics = ({ good, neutral, bad }) => {
  let all = good+neutral+bad
  let average = (good-bad)/(all)
  let positive = ((good/all) * 100).toString() + ' %'
  
  // Display no feedback if none has been given, 
  // else fall down to return statistics lines
  if (all === 0) {
    return (
      <div>
        No feedback has been given
      </div>
    )
  }

  return (
    <table>
      <tbody>
        <StatisticsLine text='good' counter={good} />
        <StatisticsLine text='neutral' counter={neutral} />
        <StatisticsLine text='bad' counter={bad} />
        <StatisticsLine text='all' counter={all} />
        <StatisticsLine text='average' counter={average} />
        <StatisticsLine text='positive' counter={positive} />
      </tbody>
    </table>
  )

}

const Button = ({ onClick, text }) => <button onClick={onClick}>{text}</button>

const App = () => {
  // save clicks of each button to its own state
  const [good, setGood] = useState(0)
  const [neutral, setNeutral] = useState(0)
  const [bad, setBad] = useState(0)

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
      <Statistics good={good} neutral={neutral} bad={bad}/>
    </div>
  )
}

export default App