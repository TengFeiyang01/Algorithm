namespace rest_api_cs
{
    public class User
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Role { get; set; }
    }

    public interface IRepository
    {
        User[] GetUsers();
    }


    [ApiController]
    [Route("[controller]")]
    public class UsersController : ControllerBase
    {
        private IRepository _repository;
        private readonly LoggerProxy _logger;

        public UsersController(IRepository repository, LoggerProxy logger)
        {
            _repository = repository;
            _logger = logger;
        }

        [HttpGet]
        public IActionResult GetUsers([FromQuery] string name)
        {
            var users = _repository.GetUsers();

            if (!string.IsNullOrEmpty(name))
            {
                users = users.Where(u => u.Name.Equals(name, StringComparison.OrdinalIgnoreCase)).ToArray();
            }

            return Ok(users);
        }
    }
}