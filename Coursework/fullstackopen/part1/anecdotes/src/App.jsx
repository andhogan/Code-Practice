import { useState } from 'react'

const Header = ({ text }) => <h1>{text}</h1>

const Button = ({ onClick, text }) => <button onClick={onClick}>{text}</button>

const MostVotes = ({ votes, mostVoted, mostVotedAnecdote }) => {
  let blankArray = Array(votes.length).fill(0)
  if (votes === blankArray) {
    return (
      <div>
        No votes have been received.
      </div>
    )
  }

  return (
    <div>
      {mostVotedAnecdote} 
      <br></br>
      <br></br>
      This anecdote has {votes[mostVoted]} upvotes.
    </div>
  )
}

const App = () => {
  const anecdotes = [
    'If it hurts, do it more often.',
    'Adding manpower to a late software project makes it later!',
    'The first 90 percent of the code accounts for the first 90 percent of the development time...The remaining 10 percent of the code accounts for the other 90 percent of the development time.',
    'Any fool can write code that a computer can understand. Good programmers write code that humans can understand.',
    'Premature optimization is the root of all evil.',
    'Debugging is twice as hard as writing the code in the first place. Therefore, if you write the code as cleverly as possible, you are, by definition, not smart enough to debug it.',
    'Programming without an extremely heavy use of console.log is same as if a doctor would refuse to use x-rays or blood tests when diagnosing patients.',
    'The only way to go fast, is to go well.'
  ]
   
  const [selected, setSelected] = useState(0)
  const [votes, setVotes] = useState(Array(anecdotes.length).fill(0))
  const [mostVoted, setMostVoted] = useState(selected)
  const votesCopy = [...votes]

  const getRandomInt = (max) => {
    return Math.floor(Math.random() * max)
  }

  const genRandomAnecdote = () => {
    // console.log('Selecting new anecdote...')
    setSelected(getRandomInt(anecdotes.length))
  }

  const upVote = () => {
    // console.log('Votes:', votes)
    // console.log('Votes Copy:', votesCopy)
    votesCopy[selected] += 1
    setVotes(votesCopy)
    if (votesCopy[selected] > votesCopy[mostVoted]) {
      setMostVoted(selected)
    }
  }

  return (
    <div>
      <Header text='Anecdote of the Day' />
      <p>{anecdotes[selected]}</p>
      {/* <p>Selected: {selected}</p> */}
      <Button onClick={genRandomAnecdote} text='next anecdote'/>
      <Button onClick={upVote} text='vote' />
      <p>This anecdote has {votesCopy[selected]} upvotes.</p>
      <Header text='Most Highly Voted Anecdote' />
      <MostVotes votes={votes} mostVoted={mostVoted} mostVotedAnecdote={anecdotes[mostVoted]}/>
    </div>
  )
}

export default App