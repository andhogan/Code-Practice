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

const Course = ({ courses }) => {
  return (
    <>
      {courses.map(course => {
        return (
        <>
          <Header name={course.name} key={course.id}/>
          <Content parts={course.parts} key={course.id} />
        </>
        )
      }
    )}
    </>
  )
}

const App = () => {
const courses = [
    {
      name: 'Half Stack application development',
      id: 1,
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
        },
        {
          name: 'Redux',
          exercises: 11,
          id: 4
        }
      ]
    }, 
    {
      name: 'Node.js',
      id: 2,
      parts: [
        {
          name: 'Routing',
          exercises: 3,
          id: 1
        },
        {
          name: 'Middlewares',
          exercises: 7,
          id: 2
        }
      ]
    }
  ]

  return <Course courses={courses} />
}

export default App
