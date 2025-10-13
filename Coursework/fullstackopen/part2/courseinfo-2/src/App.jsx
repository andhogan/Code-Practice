import { useState } from 'react'

const Header = ({ name }) => {
  return (
    <div>
      <h1>{name}</h1>
    </div>
  )
}

const Part = ({ part, exercises }) => {
  return (
    <div>
      <p>
        {part} {exercises}
      </p>
    </div>
  )
}

const Content = ({ parts }) => {
  const total = parts.reduce((sum, part) => {
    // console.log('This is sum:', sum, 'This is part:', part, 'This is sum+part.exercises', sum+part.exercises)
    return sum + part.exercises}, 0
  )
  return (
    <>
      {parts.map(obj => <Part key={obj.id} part={obj.name} exercises={obj.exercises}/>)}
      <p><strong>Total of {total} exercises</strong></p>
    </>
  )
}

const Course = ({ course }) => {
  return (
    <>
      <Header name={course.name}/>
      <Content parts={course.parts} />
    </>
  )
}

const App = () => {
  const course = {
    id: 1,
    name: 'Half Stack application development',
    parts: [
      {
        name: 'Fundamentals of React',
        exercises: 10,
        id: 1
      },
      {
        name: 'Using props to pass data',
        exercises: 7,
        id: 2
      },
      {
        name: 'State of a component',
        exercises: 14,
        id: 3
      }
    ]
  }

  return <Course course={course} />
}

export default App
