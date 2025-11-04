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
      {courses.map(course => (
        <div key={course.id}>
          <Header name={course.name} />
          <Content parts={course.parts} />
        </div>
      ))}
    </>
  )
}

export default Course
